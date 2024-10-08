SELECT MONTH(START_DATE) MONTH, CAR_ID, COUNT(HISTORY_ID) RECORDS
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
WHERE CAR_ID IN (SELECT CAR_ID
                 FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
                 WHERE MONTH(START_DATE) IN (8, 9, 10)
                 GROUP BY CAR_ID
                 HAVING COUNT(HISTORY_ID) >= 5)
AND MONTH(START_DATE) IN (8, 9, 10)
GROUP BY MONTH, CAR_ID
HAVING COUNT(HISTORY_ID) >= 1
ORDER BY MONTH, CAR_ID DESC;