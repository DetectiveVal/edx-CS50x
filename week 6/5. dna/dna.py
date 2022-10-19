import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Correct usage: Usage: python dna.py data.csv sequence.txt")
        exit()

    # TODO: Read database file into a variable
    dictDatabase = []
    database = sys.argv[1]
    with open(database) as csvfile:
        reader = csv.DictReader(csvfile)
        for i in reader:
            dDatabase = i
            dictDatabase.append(dDatabase)

    # TODO: Read DNA sequence file into a variable
    sequence = sys.argv[2]
    with open(sequence, "r") as textfile:
        reader = textfile.read()

    # TODO: Find longest match of each STR in DNA sequence
    subsequences = []
    for i in dictDatabase[0].keys():
        subsequences.append(longest_match(reader, i))

    # TODO: Check database for matching profiles
    for i in range(len(dictDatabase)):
        values = list(dictDatabase[i].values())
        counter = 0
        for n in range(len(subsequences)):
            if str(subsequences[n]) == values[n]:
                counter += 1
            if counter == (len(subsequences) - 1):
                print(dictDatabase[i]["name"])
                exit()
        if i == (len(dictDatabase) - 1) and counter != 3:
            print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
