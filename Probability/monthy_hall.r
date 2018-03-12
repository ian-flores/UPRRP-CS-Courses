
# How many times to runs the experiment
samples <- sample(10:50000)[1]

# Doors from the monthy hall problem
door <- c("Door1","Door2", "Door3")

# How many times was the door with the car selected in the first try 
wins1 <- c(0)

# How many times was the door with the car selected after switching 
wins2 <- c(0)

# doors
d1 <- 0
d2 <- 0
d3 <- 0

# Run experiment "samples" times
for (i in 1:samples)
{
  # Random door that contains the car
  car <- sample(door)[1]
  
  # First door selected by player
  choice1 <- sample(door)[1]
  
  # Reveal a GOAT!!!!!
  reveal <- sample(door[door != car & door != choice1])[1]
  
  # Second door selected by player
  choice2 <- sample(door[door != reveal & door != choice1])[1]
  
  # count wins 
  if (car == choice1) {wins1 = (wins1 + 1)}
  if (car == choice2) {wins2 = (wins2 + 1)}
  
  # count winning door
  if (car == "Door1") {d1 = d1 + 1}
  if (car == "Door2") {d2 = d2 + 1}
  if (car == "Door3") {d3 = d3 + 1}
  
  # count losses
  if (choice1 != car & choice2 != car) {losses = losses + 1}
}

# Ratio of wins on first choice
ratio1 <- wins1/samples

# Ratio of wins on second choice
ratio2 <- wins2/samples

# Plotable Data Frame 
win_data <- c(wins1, wins2)
win_rat <- c(ratio1, ratio2)
l <- c(d1, d2, d3)

# Partition Graphical output
X <- par(mfrow = c(2,3))

# Barplots
barplot(win_data, width = 1,names.arg = c("1st choice","2nd choice"), xlab = "Choices", ylab = "Wins", main = "Wins per choice")
barplot(win_rat, width = 1,names.arg = c("1st choice", "2nd choice"), xlab = "Choices", ylab = "Ratio", main = "Ratio of Wins per choice")
barplot(l,width = 1,names.arg = c("Door 1","Door 2", "Door 3"), xlab = "Doors", ylab = "Number of wins", main = "Winning door")

# Dotchart plots
dotchart( win_data, labels = c("1st choice","2nd choice"), main = "Wins per choice")
dotchart( win_rat, labels = c("1st choice", "2nd choice"), main = "Ratio of Wins per choice")
dotchart(l, labels = c("Door 1","Door 2", "Door 3"), main = "Winning door")

