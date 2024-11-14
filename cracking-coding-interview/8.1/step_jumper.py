import math

jump_values = [1,2,3]
step_count = 47
match_count = 0

for i in range(math.floor(step_count / jump_values[0])):
    for j in range(math.floor(step_count / jump_values[1])):
        for k in range (math.floor(step_count / jump_values[2])):
            if (i * jump_values[0] + j * jump_values[1] + k * jump_values[2] == step_count):
                match_count = match_count + 1
                print("1 " + str(i) + " 2 " + str(j) + " 3 " + str(k) + " " + str(match_count))
