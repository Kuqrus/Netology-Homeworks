create table Genre(
	Id serial primary key,
	Name varchar(40) not null
);

create table Artist(
	Id serial primary key,
	Name varchar(40) not null
);

create table Genre_Artist (
	Genre_Id integer references Genre(Id),
	Artist_Id integer references Artist(Id),
	primary key (Genre_Id, Artist_Id)
);

create table Album (
 	Id serial primary key,
 	Title varchar(40) not null,
 	Release date not null
);

create table Artist_Album(
	Artist_Id integer references Artist(Id),
	Album_Id integer references Album(Id),
	primary key (Artist_Id, Album_Id)
);

create table Track (
	Id serial primary key,
	Album_Id integer references Album(Id),
	Title varchar(80) not null,
	Lenght time not null
);


create table MixTape (
	Album_Id integer references Album(Id),
	Track_Id integer references Track(Id),
	Release date not null
);