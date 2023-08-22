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

	// Функция выводит список всех клиентов и возвращает выбранный ID
	// Либо при вводе -1 выходит в главное меню
	int ClientId(pqxx::work& x);

	// Функиця принимает на вход ID конкретного клиента и выводит список его телефонов
	// Если телефоны отсутсвуют выводит это
	void ShowPhones(pqxx::work& x, int id);
};

void execute();