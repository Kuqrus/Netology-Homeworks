-- 2-1
select title, lenght
from track
where lenght = (select max(lenght) from track);

-- 2-2
select title, lenght
from track
where lenght >= '00:03:30';

-- 2-3
select distinct  title
from mixtape
where release >= '2018-01-01' and release < '2021-01-01';

-- 2-4
select name
from artist
where name not like '% %';

-- 2-5
select title
from track
where title like '%My%' or title like '%Мой%';

-- 3-1
select g.name, count(ga.artist_id) count  from genre g 
join genre_artist ga on g.id = ga.genre_id 
group by g.name
order by count desc;


-- 3-2
select t.title, a.release from album a 
join track t on a.id = t.album_id
where a.release >= '2019-01-01' and a.release < '2021-01-01'
group by t.title, a.release;

-- 3-3
select a.title as Album_Title, avg(t.lenght) as lenght  from album a
join track t on a.id = t.album_id
group by a.title
order by lenght desc;

-- 3-4
select ar.name, al.title, al.release  from artist ar
join artist_album aa ON aa.artist_id = ar.id 
join album al on al.id = aa.album_id
where al.release < '2020-01-01' or al.release >= '2021-01-01'
group by ar.name, al.title, al.release;

-- 3-5
select distinct m.title from mixtape m 
join artist_album aa on aa.album_id = m.album_id 
join artist ar on ar.id = aa.artist_id 
where ar.name like 'Wasted One';

-- 4-1
select al.title, count(ga.genre_id) from artist ar
join genre_artist ga on ga.artist_id = ar.id
join artist_album aa on aa.artist_id = ar.id 
join album al on al.id = aa.album_id 
group by al.title
having count(ga.genre_id) > 1

-- 4-2
select t.title from track t 
left join mixtape m on m.track_id = t.id
group by t.title
having count(m.track_id) = 0

-- 4-3
select ar.name, t.title, t.lenght as shortest_track from track t
join album al on al.id = t.album_id 
join artist_album aa on aa.album_id = al.id 
join artist ar on ar.id = aa.artist_id 
where t.lenght = (select min(lenght) from track)
group by ar.name, t.title, t.lenght 

-- 4-4
select al.title, count(t.album_id) as count from album al
join track t on t.album_id = al.id 
group by al.title 
having count(t.album_id) = (select min(album_id) from track)









