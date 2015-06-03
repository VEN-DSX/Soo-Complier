#pragma once
#ifndef _SYMBOLTABLE_H
#define _SYMBOLTABLE_H
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include "Lexer.h"
#include "Global.h"
using namespace std;
/*
	���ű�ϵͳ
	�ڱ�������з��ű�������ų����г��ֵ��йر�ʶ����������Ϣ
*/
struct Symbol;
struct SymbolTable_Node;
//������������
struct Symbol_Array
{
	int Length;//����ά��
};
//������ʽ����
struct Symbol_FuncParam
{
	Data_Type type;//��������
	string name; //��������
};
//�ṹ����������
struct Symbol_Struct
{
	vector<Symbol> Struct_Number;//�ṹ���е����ݳ�Ա
};
//������������
struct Symbol_Function
{
	Data_Type Func_Type;//������������
	int Func_Address;//������ڵ�ַ
	vector<Symbol_FuncParam> Func_ParamList;//��������ʽ����
};
//��ʶ���ڵ�ṹ
struct Symbol
{
	string Name;//��ʶ������
	TypeCode Type;//��ʶ������
	Data_Type DType;//��������
	int Address;//���ŵ�ַ����������������ġ����пռ䡱�е�λ��
	Symbol_Array * Symbol_array;//��ʶ����ʾ������Ϊ����
	Symbol_Function * Symbol_function;//��ʶ����ʾ������Ϊ����
	Symbol_Struct * Symbol_struct;//��ʶ����ʾ������Ϊ�ṹ��
	SymbolTable_Node * Front;//��ͬ������ı�ʶ����ǰһ�����ӵı�ʶ��
	SymbolTable_Node * Link;//��ͬ������ı�ʶ��,��һ�����ӵı�ʶ��
};
//���ű����ṹ
struct SymbolTable_Node
{
	Symbol SymbolData;//�ڵ�����
	SymbolTable_Node * Root;	//���ڵ�
	SymbolTable_Node * Child;	//�ӽڵ�
};
//���ű�ϵͳ��
class Symbol_System
{
public:
	static Symbol_System & Symbol_SystemInstance();	//ʵ����
	static SymbolTable_Node * SymbolPointer;//���дʷ�����ʱ���ű���ʵʱָ��
	SymbolTable_Node * SymbolTreeRoot;					//���ű������ṹ���ڵ�
	void Symbol_CreateTree();							//�������ű�ϵͳ���νṹ
	void Symbol_Add(Symbol Symboldata,External state);	//�����ż������νṹ���ű�ϵͳ
	void Symbol_Delete(string symbolname, TypeCode type, Data_Type dtype);//�����Ŵ����νṹ���ű�ϵͳɾ��
	SymbolTable_Node* Symbol_Search(string symbolname, TypeCode type, Data_Type dtype);//���ű��еı�ʶ������,�������ű����νṹ

};
//����ϵͳ��ʵ����
Symbol_System & Symbol_System::Symbol_SystemInstance()
{
	static Symbol_System symbol;
	return symbol;
}

#endif 