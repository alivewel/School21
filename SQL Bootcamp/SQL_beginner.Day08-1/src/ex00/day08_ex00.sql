-- **Session #1**
begin;
select * from pizzeria where name  = 'Pizza Hut';
update  pizzeria set rating = 5 where name = 'Pizza Hut';
-- **Session #2**
select * from pizzeria where name  = 'Pizza Hut';
-- **Session #1**
commit;
-- **Session #2**
select * from pizzeria where name  = 'Pizza Hut';