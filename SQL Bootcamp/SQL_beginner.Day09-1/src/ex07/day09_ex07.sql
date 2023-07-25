CREATE OR REPLACE FUNCTION func_minimum(VARIADIC arr NUMERIC[])
RETURNS NUMERIC AS
$$
DECLARE
  min_val NUMERIC;
BEGIN
  SELECT MIN(val) INTO min_val
  FROM UNNEST(arr) AS val;
  RETURN min_val;
END;
$$ LANGUAGE plpgsql;

SELECT func_minimum (VARIADIC arr => ARRAY [10.0, -1.0, 5.0, 4.4]);
