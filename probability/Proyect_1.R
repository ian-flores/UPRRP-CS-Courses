library(PASWR)

# (a) Use the function merge() to combine the data frames WheatSpain (from problem 3)
# and SurfaceSpain into a new data frame named DataSpain.
DataSpain <- merge(WheatSpain, SurfaceSpain)
head(DataSpain)

# (b) Create a variable named surface.h containing the surface area of each autonomous
# community in hectares. (Note: 100 hectares = 1 km 2 .) Create a variable named
# wheat.p containing the percent surface area in each autonomous community ded-
#   icated to growing wheat. Add the newly created variables to the data frame
# DataSpain and store the result as a data frame with the name DataSpain.m.
surface.h <- (DataSpain$surface)*100
wheat.p <- ((DataSpain$hectares)/surface.h)*100
DataSpain['Surface_Hectares'] = surface.h
DataSpain['Wheat_Percentage'] = wheat.p

# (c) Assign the names of the autonomous communities as row names for DataSpain.m
# and remove the variable community from the data frame.
rownames(DataSpain) <- DataSpain$community
DataSpain$community <- NULL

# (d) Create a barplot showing the percent surface area dedicated to growing wheat for
# each of the seventeen Spanish autonomous communities. Arrange the communities
# by decreasing percentages.
library(ggplot2)
ggplot(DataSpain, aes(x = reorder(rownames(DataSpain), -Wheat_Percentage), y = Wheat_Percentage)) + 
  geom_bar(stat = 'identity') + 
  labs(x = "Autonomous Communities", y = "Wheat Percentage", 
       title = "Percent surface area dedicated to growing wheat per community", 
       caption = "Data from the PASWR package") + 
  theme_bw() + 
  theme(panel.border = element_blank(), panel.grid.major = element_blank(),
        panel.grid.minor = element_blank(), axis.line = element_line(colour = "black"))

# (e) Display the percent surface area dedicated to growing wheat for each of the seventeen
# Spanish autonomous communities using the function dotchart(). To read about
# dotchart(), type ?dotchart at the command prompt. Do you prefer the barchart
# or the dotchart? Explain your answer.
dotchart(DataSpain$Wheat_Percentage, labels = rownames(DataSpain), 
         xlab = "Wheat Percentage", 
         main = "Percent surface area dedicated to growing wheat per community")

# (f) Describe the relationship between the surface area in an autonomous community
# dedicated to growing wheat (hectares) and the total surface area of the autonomous
# community (surface.h).

ggplot(DataSpain, aes(x = Surface_Hectares, y =  hectares, color=rownames(DataSpain))) +
  geom_point() + 
  labs(x = "Total Surface Area (Hectares)", y = "Surface Area dedicated to growing Wheat (Hectares)", 
       title = "Relationship between the surface area dedicated to growing wheat and Total Surface Area", 
       colour = "Autonomous Community",
       caption = "Data from the PASWR package") + 
  theme_bw() + 
  theme(panel.border = element_blank(), panel.grid.major = element_blank(),
        panel.grid.minor = element_blank(), axis.line = element_line(colour = "black"))
cor(DataSpain$Surface_Hectares, DataSpain$hectares) 


# (g) Describe the relationship between the surface area in an autonomous community
# dedicated to growing wheat (hectares) and the percent of surface area dedicated to
# growing wheat out of the communities’ total surface area (wheat.p).

ggplot(DataSpain, aes(x = hectares, y = Wheat_Percentage, color=rownames(DataSpain))) +
  geom_point() + 
  labs(x = "Surface Area dedicated to growing Wheat (Hectares)", y = "Wheat Percentage", 
       title = "Relationship between the surface area dedicated to growing wheat and \nthe percent surface area dedicated to growing wheat", 
       colour = "Autonomous Community",
       caption = "Data from the PASWR package") + 
  theme_bw() + 
  theme(panel.border = element_blank(), panel.grid.major = element_blank(),
        panel.grid.minor = element_blank(), axis.line = element_line(colour = "black"))
cor(DataSpain$hectares, DataSpain$Wheat_Percentage) 

# (h) Develop a model to predict the surface area in an autonomous community dedicated
# to growing wheat (hectares) based on the total surface area of the autonomous
# community (surface.h).

l_m <- lm(DataSpain$hectares~surface.h)
summary(l_m)

ggplot(DataSpain, aes(x = Surface_Hectares, y =  hectares, color=rownames(DataSpain))) +
  geom_point() + 
 geom_abline(intercept = l_m$coefficients[1], slope = l_m$coefficients[2]) +
  labs(x = "Total Surface Area (Hectares)", y = "Surface Area dedicated to growing Wheat (Hectares)", 
       title = "Relationship between the surface area dedicated to growing wheat and Total Surface Area", 
       colour = "Autonomous Community",
       caption = "Data from the PASWR package") + 
  theme_bw() + 
  theme(panel.border = element_blank(), panel.grid.major = element_blank(),
        panel.grid.minor = element_blank(), axis.line = element_line(colour = "black"))
