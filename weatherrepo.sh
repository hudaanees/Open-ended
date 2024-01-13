#!/bin/bash

# Your C program executable to analyze environmental data
./your_c_program_executable

# Check if processoutput.txt is generated
if [ -e "processoutput.txt" ]; then
    echo "Sending email report..."

    # Prepare email content
    email_content="Subject: Weather Report\n\n$(cat processoutput.txt)"

    ./m

    echo "Email report sent."
else
    echo "Error: processoutput.txt not found."
fi
