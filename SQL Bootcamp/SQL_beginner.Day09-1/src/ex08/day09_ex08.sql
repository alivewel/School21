CREATE OR REPLACE FUNCTION fnc_fibonacci(pstop integer DEFAULT 10)
RETURNS TABLE (fibonacci_number bigint) AS
$$
DECLARE
  fib1 bigint := 0;
  fib2 bigint := 1;
  fib_next bigint;
BEGIN
  IF pstop > 0 THEN
    RETURN QUERY SELECT fib1;
  END IF;

  RETURN QUERY SELECT fib2;

  LOOP
    fib_next := fib1 + fib2;
    EXIT WHEN fib_next >= pstop;

    RETURN QUERY SELECT fib_next;

    fib1 := fib2;
    fib2 := fib_next;
  END LOOP;

  RETURN;
END;
$$ LANGUAGE plpgsql;


SELECT * FROM fnc_fibonacci(100);

SELECT * FROM fnc_fibonacci();
