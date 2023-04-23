# Set the base image to use
FROM gcc:latest
# Copy the C program into the container
COPY Program1_HamzaJalil.c .
# Compile the C program
RUN gcc -o Program1_HamzaJalil Program1_HamzaJalil.c
# Set the command to run when the container starts
CMD ["./Program1_HamzaJalil"]
