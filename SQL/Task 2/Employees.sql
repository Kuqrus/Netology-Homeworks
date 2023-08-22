create table if not exists Employees(
	EmployeeId serial primary key,
	Name varchar(40) not null,
	Dept varchar(80) not null,
	Head integer not null references Employees(EmployeeId)
);