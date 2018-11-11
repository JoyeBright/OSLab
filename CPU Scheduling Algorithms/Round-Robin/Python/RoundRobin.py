import copy

# declare a dictionary where keys are processes' names and value of each key is the burst time of that process
processes = {}
# declare a dictionary of waiting time to store each process's waiting time
waiting_time = {}

number_of_processes = int(input("Please enter the number of processes: "))
for i in range(number_of_processes):
    burst_time = input("Please enter the burst time of process " + str(i+1) + ": ")
    processes[i] = int(burst_time)
    waiting_time[i] = 0

# get a copy of burst times to keep track of remaining burst times
remaining_burst_time = copy.deepcopy(processes)

# declare the size of quantum slice
quantum = int(input("Please enter the quantum size: "))

# declare the overall executing time of the processor
total_time = 0

# until all processes have finished executing
while any(value != 0 for value in remaining_burst_time.values()):

    # calculate the remaining burst time and process it if needed
    for i in range(len(processes)):

        # check if the remaining burst time is larger than the quantum
        # so that all of quantum must be given to this process
        if remaining_burst_time[i] > quantum:
            total_time += quantum
            remaining_burst_time[i] -= quantum

        # if remaining burst time is smaller than the quantum, the process will finish its's execution
        # and what's left of the quantum will be spent on next process
        else:
            total_time += remaining_burst_time[i]
            # calculate the waiting time of the process
            waiting_time[i] = total_time - processes[i]
            remaining_burst_time[i] = 0


# calculate the average waiting time
total_waiting_time = 0
for i in waiting_time.values():
    total_waiting_time += i
average_waiting_time = total_waiting_time / number_of_processes


# calculate the average turnaround time (enter time of all processes are 0, by default)
# if you want it, i can write another code to determine different in-time for each process
total_turnaround_time = 0
for item in range(number_of_processes):
    total_turnaround_time += waiting_time[item] + processes[item]
average_turnaround_time = total_turnaround_time / number_of_processes


print("\n\nThe average waiting time is: " + str(average_waiting_time))
print("The average turnaround time is: " + str(average_turnaround_time))
