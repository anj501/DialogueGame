# DialogueGame
-1 v 1 BallSport game that consists mostly of dialogue and strategy

-Randomizes numbers for parts of the game such as scoring ability, defense, rebounding, and who gets the ball

## Important Game Features

-There are three different types of ballers (fire, water, and ice) with some being effective against others

-There are different styles of ballers (scorer, defender, and all-arounder) within the types and they      
  specialize in their strengths.
  
-Scoring (every character will score unless they cannot obtain a rebound) adds points to your score,       
  choosing defensive preference will allow you take away points from your opponent's score, and
  a rebounding preference will secure a posession for you after you defend
  (the competitor will be asked if they would like a defensive or rebounding preference)
  
-There will be times where the dialogue may be long if a competitor is unable to grab a rebound. You can
  either choose to read the entire dialogue or look at the current score and proceed with the game.
  
-The game will go on until a team reaches 20 points
 
-Even if a competitor secures a possession with a rebound, if the opposition scores over 20, the game
  will end
  
###### To compile files use: 
  ```
  g++ main.cpp fire.cpp water.cpp ice.cpp game.cpp
  ```
