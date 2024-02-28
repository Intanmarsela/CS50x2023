--To get into the crime scene report in 28 July on Humphrey Street.
SELECT * FROM crime_scene_reports WHERE day = 28 AND month = 7
AND street = 'Humphrey Street' AND description LIKE "%duck%";

--From the report, we have to look into interviews on that day and all the interviewee mention about "bakery".
SELECT * FROM interviews WHERE day = 28 AND month = 7 AND transcript LIKE ("%bakery%");

--First Witness
SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND activity = "exit" AND hour = 10;

--Second Witness
SELECT * FROM atm_transactions
JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
WHERE atm_location = 'Leggett Street' AND transaction_type = 'withdraw'
AND bank_accounts.account_number IN (SELECT bank_accounts.account_number FROM bank_accounts
JOIN people ON bank_accounts.person_id = people.id
WHERE name = "Bruce"
) AND day = 28;

--Third Witness
-- The under 1 minute call
SELECT caller, receiver, month, day, duration FROM phone_calls
JOIN people ON phone_calls.caller = people.phone_number
WHERE name = "Bruce" AND duration <= 60 AND day = 28;
-- Checking the receiver phone number identity
SELECT * FROM people WHERE phone_number = "(375) 555-8161";

-- First flight out from Fiftyvalle
SELECT
    f.id AS flight_id,
    f.year,
    f.month,
    f.day,
    f.hour,
    f.minute,
    origin_city.city AS origin_city,
    destination_city.city AS destination_city
FROM flights f
JOIN airports origin_city ON f.origin_airport_id = origin_city.id
JOIN airports destination_city ON f.destination_airport_id = destination_city.id
WHERE origin_city = "Fiftyville" AND day = 29 AND month = 7 ORDER BY hour LIMIT 1;
--Bruce is in the list of passanger.
SELECT flight_id,people. passport_number AS passport_number ,seat FROM passengers
JOIN people ON passengers.passport_number = people.passport_number
WHERE name = "Bruce";
