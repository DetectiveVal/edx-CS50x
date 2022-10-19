-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Trying to find when the crime happened
SELECT crime_scene_reports.id, day,month,year,crime_scene_reports.street,crime_scene_reports.description FROM crime_scene_reports;
-- Seeing the activity at the bakery at the time of the crime and the surrouding hours
SELECT * FROM bakery_security_logs;
-- Valuable witness information that lead to the next few steps.
SELECT name, day, month, year, transcript FROM interviews;
-- Getting the names of the people who left the bakery by car within 10 minutes of the crime due to a witness report.
SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND month = 7 AND hour = 10 AND activity = "exit" AND (minute > 15 OR minute < 25));
-- Name of people that withdrew money on the day of the crime as per witness report.
SELECT people.name, FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number WHERE atm_transactions.day = 28 AND atm_transactions.month = 7 AND atm_transactions.atm_location = "Leggett Street" AND atm_transactions.transaction_type = "withdraw" AND atm_transactions.year = 2021;
-- Get the fiftyville airport ID
SELECT * FROM airports;
-- Name of people booking a flight out of the city on the next day as per witness report.
SELECT people.name,flights.hour FROM people JOIN passengers ON people.passport_number = passengers.passport_number JOIN flights ON passengers.flight_id = flights.id WHERE flights.origin_airport_id = "8" AND day = 29 AND month = 7 ORDER BY flights.hour ASC;
-- Name of people who made a call that lasted less than 1 minute at 10:15am on the 28th
SELECT people.name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE day = 28 AND month = 7 AND duration < 60);
-- Get Bruce's information
SELECT * FROM people WHERE name = "Bruce";
-- Find the acomplice
SELECT people.name FROM people WHERE phone_number IN(SELECT receiver FROM phone_calls WHERE caller = "(367) 555-5533" AND day = 28 AND month = 7 AND duration < 60);
-- Find the city he fled to
SELECT airports.city FROM airports WHERE airports.id = (SELECT flights.destination_airport_id FROM flights JOIN passengers ON passengers.flight_id = flights.id WHERE passengers.passport_number = "5773159633");