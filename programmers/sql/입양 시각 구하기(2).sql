SET @hour := -1;

SELECT (@hour := @hour + 1) HOUR, (SELECT COUNT(*) FROM ANIMAL_OUTS WHERE HOUR(DATETIME) = @hour) COUNT
FROM ANIMAL_OUTS
WHERE @hour < 23;