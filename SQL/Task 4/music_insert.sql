insert into genre
VALUES(1, 'Rock');
insert into genre 
values(2, 'Rap');
insert into genre 
values(3, 'Electro');

insert into artist(name)
values ('San Lunar');
insert into artist (name)
values ('Gummy Impact');
insert into artist(name)
values ('Wasted One');
insert into artist (name)
values ('Roland Vertex');

insert into genre_artist 
values (1, 1);
insert into genre_artist 
values (2, 1);
insert into genre_artist 
values (3, 2);
insert into genre_artist 
values (3, 3);
insert into genre_artist 
values (2,4);
insert into genre_artist 
values (3,4);

insert into album (title, release)
values ('Getting Dark', '2020-05-15');
insert into album (title, release)
values ('Most High', '2023-01-2');
insert into album (title, release)
values ('101st time', '2013-02-03');
insert into album (title, release)
values ('Far Horizon', '2018-04-29');
insert into album (title, release)
values ('Dawn', '2021-12-05');

insert into artist_album 
values (1,1);
insert into artist_album 
values (2,2);
insert into artist_album 
values (3,3);
insert into artist_album 
values (3,4);
insert into artist_album 
values (4,5);

insert into track (album_id, title, lenght)
values (1, 'Shed Your Travails', '00:03:12');
insert into track (album_id, title, lenght)
values  (1, 'The City Gates', '00:03:46');
insert into track (album_id, title, lenght)
values  (2, 'Awake', '00:01:32'); 
insert into track (album_id, title, lenght)
values  (3, 'Nerevar Rising', '00:01:54');
insert into track (album_id, title, lenght)
values  (3, 'Peaceful Waters', '00:03:05');
insert into track (album_id, title, lenght)
values  (4, 'Kynes Peace', '00:03:49');
insert into track (album_id, title, lenght)
values  (5, 'Peace of Akatosh', '00:04:11');
insert into track (album_id, title, lenght)
values  (5, 'Wings of Kynareth', '00:03:30');

insert into artist (name)
values ('Secunda');
insert into track (album_id, title, lenght)
values (3, 'Run For My Dogs', '00:03:25');
insert into genre_artist 

insert into mixtape (album_id, track_id, title, release)
values (1, 2, 'Best Of Getting Dark', '2020-07-15');
insert into mixtape (album_id, track_id, title, release)
values (3, 8, 'Best Of 101st time', '2013-04-03');
insert into mixtape (album_id, track_id, title, release)
values (5, 6, 'Best of Dawn', '2022-02-05');
insert into mixtape (album_id, track_id, title, release)
values (3, 4, 'Wasted One Discography', '2019-05-29');
insert into mixtape (album_id, track_id, title, release)
values (3, 8, 'Wasted One Discography', '2019-05-29');
insert into mixtape (album_id, track_id, title, release)
values (4, 5, 'Wasted One Discography', '2019-05-29');








