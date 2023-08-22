#include "db_editor.h"

DB_Editor::DB_Editor() {
	pqxx::work worker(conct);

	worker.exec("create table if not exists client("
		"Id serial primary key, "
		"Name text not null, "
		"email text not null"
		");"
	);

	worker.exec("create table if not exists phone("
		"Id serial primary key, "
		"Client_Id integer references client(Id), "
		"phone text not null"
		");"
	);
	worker.commit();
}

void DB_Editor::AddClient() {

	pqxx::work x{ conct };
	std::string name, email;

	std::cout << "Enter name: ";
	//std::cin >> name;

	std::getline(std::cin, name);

	std::cout << "Enter e-mail: ";
	std::cin >> email;

	x.exec("INSERT INTO public.client (name,email)"
		"VALUES('" + x.esc(name) + "', '" + x.esc(email) + "')");
	x.commit();


	pqxx::work p{ conct };
	char act;
	while (true)
	{
		std::cout << "Add phone number? (y/n): ";
		std::cin >> act;

		if (act == 'n') break;
		else if (act == 'y') {
			std::string phone;
			std::cout << "Enter phone number: ";
			std::cin >> phone;
			int client_id = p.query_value<int>("SELECT id FROM public.client WHERE name= '" + name + "'");
			p.exec("INSERT INTO public.phone (client_id, phone) VALUES('" + std::to_string(client_id) + "','" + p.esc(phone) + "')");
		};
	}
	p.commit();
}

void DB_Editor::AddPhone() {
	char act = 'y';
	pqxx::work p{ conct };
	std::string phone;


	while (act != 'n')
	{
		int client_id = ClientId(p);
		if (client_id == -1) {
			break;
		}

		ShowPhones(p, client_id);

		std::cout << "Enter new phone number or type ""back"" to return: ";
		std::cin >> phone;

		system("cls");

		if (phone == "back") {
			continue;
		}

		p.exec("INSERT INTO public.phone (client_id, phone) VALUES('" + std::to_string(client_id) + "','" + p.esc(phone) + "')");

		std::cout << "Add another phone number? (y/n): ";
		std::cin >> act;
	}
	p.commit();

}

void DB_Editor::DeletePhone() {
	char act;
	bool deleting = true;

	while (deleting)
	{
		pqxx::work p{ conct };
		int client_id = ClientId(p);
		if (client_id == -1) {
			break;
		}

		ShowPhones(p, client_id);

		if (p.query_value<int>("select count(phone) from phone where client_id='" + std::to_string(client_id) + "'") == 0) {
			std::cout << "Select another user? (y/n): ";
			std::cin >> act;
			system("cls");
			switch (act)
			{
			case 'y':
				continue;
				break;
			case 'n':
				deleting = false;
				continue;
				break;
			default:
				break;
			};
		}

		std::cout << "Delete all phone numbers? (y/n): ";
		std::cin >> act;
		system("cls");
		switch (act)
		{
		case 'y':
			p.exec("DELETE FROM public.phone WHERE client_id='" + std::to_string(client_id) + "'");
			std::cout << "Numbers deleted!" << std::endl << std::endl;
			p.commit();
			break;
		case 'n':
			std::cout << "Select another user? (y/n): ";
			std::cin >> act;
			system("cls");
			switch (act)
			{
			case 'y':
				break;
			case 'n':
				deleting = false;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}

void DB_Editor::DeleteClient() {
	char act;
	bool deleting = true;

	while (deleting)
	{
		pqxx::work p{ conct };
		int client_id = ClientId(p);
		if (client_id == -1) {
			break;
		}
		system("cls");

		std::cout << "Selected user: " << std::endl;
		for (const auto& [id, name, mail] : p.query<int, std::string, std::string>("SELECT id, name, email FROM public.client WHERE id='" + std::to_string(client_id) + "'")) {
			std::cout << "Id: " << id << " | Name: " << name << " | E-Mail: " << mail << std::endl;
		}
		ShowPhones(p, client_id);

		std::cout << "Delete all client data? (y/n): ";
		std::cin >> act;
		system("cls");
		switch (act)
		{
		case 'y':
			p.exec("DELETE FROM public.phone WHERE client_id='" + std::to_string(client_id) + "'");
			p.exec("DELETE FROM public.client WHERE id='" + std::to_string(client_id) + "'");
			std::cout << "Data deleted!" << std::endl;
			p.commit();
			break;
		case 'n':
			std::cout << "Select another user? (y/n): ";
			std::cin >> act;
			system("cls");
			switch (act)
			{
			case 'y':
				break;
			case 'n':
				deleting = false;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}

void DB_Editor::FindClient() {
	pqxx::work f{ conct };
	int search = 0, founded = 0;
	std::string info;
	char act;
	bool find = true;

	while (find)
	{
		system("cls");

		std::cout << "Search by:" << std::endl;
		std::cout << "1. Name or Surname" << std::endl;
		std::cout << "2. E-Mail" << std::endl;
		std::cout << "3. Phone Number" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cin >> search;

		system("cls");

		switch (search)
		{

			// Поиск по имени
		case 1:
			std::cout << "Enter name or surname: ";
			std::cin >> info;
			std::cout << std::endl;

			founded = f.query_value<int>("select count(name) from public.client where name like '%" + f.esc(info) + "%'");

			if (founded == 0) {
				std::cout << "No clients with this name or surname." << std::endl;
				std::cout << "Try again? (y/n): ";
				std::cin >> act;
				switch (act)
				{
				case 'y':
					continue;
					break;
				case 'n':
					system("cls");
					find = false;
					continue;
					break;
				default:
					break;
				}
				break;
			}

			else if (founded == 1) {
				for (const auto& [id, name, mail] : f.query<int, std::string, std::string>("SELECT id, name, email FROM public.client WHERE name like'%" + f.esc(info) + "%'")) {
					std::cout << "Id: " << id << " | Name: " << name << " | E-Mail: " << mail << std::endl;
					ShowPhones(f, id);
				}
			}
			else if (founded > 1) {
				for (const auto& [id, name, mail] : f.query<int, std::string, std::string>("SELECT id, name, email FROM public.client WHERE name like '%" + f.esc(info) + "%'")) {
					std::cout << "Id: " << id << " | Name: " << name << " | E-Mail: " << mail << std::endl;
					ShowPhones(f, id);
				}

			}
			break;

			// Поиск по почте
		case 2:
			std::cout << "Enter e-mail: ";
			std::cin >> info;
			std::cout << std::endl;

			founded = f.query_value<int>("select count(email) from public.client where email like '%" + f.esc(info) + "%'");

			if (founded == 0) {
				std::cout << "No clients with this e-mail." << std::endl;
				std::cout << "Try again? (y/n): ";
				std::cin >> act;
				switch (act)
				{
				case 'y':
					continue;
					break;
				case 'n':
					system("cls");
					find = false;
					continue;
					break;
				default:
					break;
				}
				break;
			}
			else if (founded == 1) {
				for (const auto& [id, name, mail] : f.query<int, std::string, std::string>("SELECT id, name, email FROM public.client WHERE email like'%" + f.esc(info) + "%'")) {
					std::cout << "Id: " << id << " | Name: " << name << " | E-Mail: " << mail << std::endl;
					ShowPhones(f, id);
				}
			}
			else if (founded > 1) {
				for (const auto& [id, name, mail] : f.query<int, std::string, std::string>("SELECT id, name, email FROM public.client WHERE email like '%" + f.esc(info) + "%'")) {
					std::cout << "Id: " << id << " | Name: " << name << " | E-Mail: " << mail << std::endl;
					ShowPhones(f, id);
				}

			}
			break;

			// Поиск по телефону
		case 3:
			std::cout << "Enter phone number: ";
			std::cin >> info;
			std::cout << std::endl;

			founded = f.query_value<int>("select count(phone) from public.phone where phone like '%" + f.esc(info) + "%'");

			if (founded == 0) {
				std::cout << "No clients with this phone number." << std::endl;
				std::cout << "Try again? (y/n): ";
				std::cin >> act;
				switch (act)
				{
				case 'y':
					continue;
					break;
				case 'n':
					system("cls");
					find = false;
					continue;
					break;
				default:
					break;
				}
				break;
			}

			else if (founded == 1) {
				int client_id = f.query_value<int>("SELECT client_id FROM public.phone WHERE phone LIKE '%" + f.esc(info) + "%'");

				for (const auto& [id, name, mail] : f.query<int, std::string, std::string>("SELECT id, name, email FROM public.client WHERE id ='" + std::to_string(client_id) + "'")) {
					std::cout << "Id: " << id << " | Name: " << name << " | E-Mail: " << mail << std::endl;
					ShowPhones(f, id);
				}

			}
			else if (founded > 1) {
				int prev_id = -1;
				for (const auto& [client_id] : f.query<int>("SELECT client_id FROM public.phone WHERE phone like '%" + f.esc(info) + "%'")) {
					if (prev_id == client_id) {
						prev_id = client_id;
						continue;
					}
					else {
						prev_id = client_id;
					}
					for (const auto& [id, name, mail] : f.query<int, std::string, std::string>(
						"SELECT id, name, email FROM public.client WHERE id ='" + std::to_string(client_id) + "'")) {
						std::cout << "Id: " << id << " | Name: " << name << " | E-Mail: " << mail << std::endl;
					}
					ShowPhones(f, client_id);
				}
			}

			break;

			// Выход
		case 0:
			return;
			break;
		default:
			break;
		}

		std::cout << std::endl << "Find another user? (y/n): ";
		std::cin >> act;
		system("cls");
		switch (act)
		{
		case 'y':
			continue;
			break;
		case 'n':
			find = false;
			continue;
			break;
		default:
			break;
		}
	}
}

void DB_Editor::ModifyClient() {
	int select;
	char act;
	std::string NewInfo;
	bool modify = true;

	while (modify)
	{
		pqxx::work x{ conct };
		int client_id = ClientId(x);
		if (client_id == -1) {
			break;
		}

		std::cout << "Selected user: " << std::endl;
		for (const auto& [id, name, mail] : x.query<int, std::string, std::string>("SELECT id, name, email FROM public.client WHERE id='" + std::to_string(client_id) + "'")) {
			std::cout << "Id: " << id << " | Name: " << name << " | E-Mail: " << mail << std::endl;
		}
		ShowPhones(x, client_id);

		std::cout << "Change:" << std::endl;
		std::cout << "1. Name" << std::endl;
		std::cout << "2. E-Mail" << std::endl;
		std::cout << "3. Phone" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cin >> select;

		system("cls");

		switch (select)
		{
		case 1:
			std::cout << "Enter new name: ";
			std::cin >> NewInfo;
			x.exec("UPDATE public.client SET name = '" + x.esc(NewInfo) + "' WHERE id = " + std::to_string(client_id) + "");

			break;
		case 2:
			std::cout << "Enter new e-mail: ";
			std::cin >> NewInfo;
			x.exec("UPDATE public.client SET email = '" + x.esc(NewInfo) + "' WHERE id = " + std::to_string(client_id) + "");

			break;
		case 3:
			if (x.query_value<int>("select count(phone) from phone where client_id='" + std::to_string(client_id) + "'") != 0) {
				ShowPhones(x, client_id);
				std::cout << "Select phone ID you want to change: ";
				std::cin >> client_id;
				system("cls");

				std::cout << "Enter new phone: ";
				std::cin >> NewInfo;

				x.exec("UPDATE public.phone SET phone = '" + x.esc(NewInfo) + "' WHERE id = " + std::to_string(client_id) + "");
			}
			else {

				std::cout << "Enter new phone: ";
				std::cin >> NewInfo;

				x.exec("INSERT INTO public.phone (client_id,phone) VALUES(" + std::to_string(client_id) + ", '" + x.esc(NewInfo) + "')");
			}
			break;

		case 0:
			return;
			break;
		default:
			break;
		}

		x.commit();
		system("cls");
		std::cout << "Change more information? (y/n): ";
		std::cin >> act;
		system("cls");
		switch (act)
		{
		case 'y':
			break;
		case 'n':
			modify = false;
			continue;
			break;
		default:
			break;
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			continue;
		}

	}
}

int DB_Editor::ClientId(pqxx::work& x) {
	int client_id;

	while (true) {
		for (const auto& [id, name, mail] : x.query<int, std::string, std::string>("SELECT id, name, email FROM public.client")) {
			std::cout << "Id: " << id << " | Name: " << name << " | E-Mail: " << mail << std::endl;
		}

		std::cout << "Enter the client id or type -1 to exit: ";
		std::cin >> client_id;

		system("cls");

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
		else if (x.query_value<int>("select count(id) from client where id = " + std::to_string(client_id) + "") > 0 || client_id == -1) {
			return client_id;
		}
		else {
			std::cout << "Incorrect ID!" << std::endl;
			continue;
		}
	}
}

void DB_Editor::ShowPhones(pqxx::work& x, int id) {
	std::cout << "User has ";
	int phone_count = x.query_value<int>("select count(phone) from phone where client_id='" + std::to_string(id) + "'");
	if (phone_count > 0) {
		std::cout << phone_count << " phone numbers:" << std::endl;
		for (const auto& [phone] : x.query<std::string>("SELECT phone FROM public.phone WHERE client_id='" + std::to_string(id) + "'")) {
			std::cout << phone << " ";
		}
	}
	else std::cout << "no phone numbers" << std::endl;
	std::cout << std::endl;
}

void execute(){
	 try {
		 DB_Editor table;
		 int act = -1;
		 while (act != 0) {
			 std::cout << "1. Add new client\n";
			 std::cout << "2. Add phone to an existing client\n";
			 std::cout << "3. Delete phone from an existing client\n";
			 std::cout << "4. Delete all data of an existing client\n";
			 std::cout << "5. Find data of an existing client (by name, surname, email, phone)\n";
			 std::cout << "6. Change data of an existing client\n";
			 std::cout << "0. Exit\n";
			 std::cin >> act;

			 system("cls");

			 if (std::cin.fail()) {
				 std::cin.clear();
				 std::cin.ignore();
				 act = -1;
				 continue;
			 }

			 switch (act)
			 {
			 case 1:
				 table.AddClient();
				 break;
			 case 2:
				 table.AddPhone();
				 break;
			 case 3:
				 table.DeletePhone();
				 break;
			 case 4:
				 table.DeleteClient();
				 break;
			 case 5:
				 table.FindClient();
				 break;
			 case 6:
				 table.ModifyClient();
				 break;
			 case 0:
				 break;
			 default:
				 break;
			 }
		 }
	 }
	 catch (const pqxx::sql_error& e) {
		 std::cout << "SQL exeption: " << e.what() << std::endl;
	 }
}