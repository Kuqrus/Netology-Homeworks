#pragma once

#include <iostream>
#include <pqxx/pqxx>

#define DBNAME "..."
#define LOGIN "..."
#define PASS "..."

class DB_Editor
{
public:
	DB_Editor();

	void AddClient();
	void AddPhone();
	void DeletePhone();
	void DeleteClient();
	void FindClient();
	void ModifyClient();

private:
	std::string conctString = "host=localhost port=5432 dbname="  DBNAME  " user=" LOGIN " password=" PASS "";
	pqxx::connection conct{ conctString };

	// ������� ������� ������ ���� �������� � ���������� ��������� ID
	// ���� ��� ����� -1 ������� � ������� ����
	int ClientId(pqxx::work& x);

	// ������� ��������� �� ���� ID ����������� ������� � ������� ������ ��� ���������
	// ���� �������� ���������� ������� ���
	void ShowPhones(pqxx::work& x, int id);
};

void execute();