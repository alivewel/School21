-- **Session #1**
begin transaction isolation level repeatable read;
-- **Session #2**
begin transaction isolation level repeatable read;
-- **Session #1**
select * from pizzeria where name  = 'Pizza Hut';
-- **Session #2**
update  pizzeria set rating = 3.6 where name = 'Pizza Hut';
commit;
-- **Session #1**
select * from pizzeria where name  = 'Pizza Hut';
commit;
select * from pizzeria where name  = 'Pizza Hut';
-- **Session #2**
select * from pizzeria where name  = 'Pizza Hut';
