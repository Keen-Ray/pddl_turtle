(define (problem turtlebot_example_task)
(:domain pddl_turtle)
(:objects
	turtle - robot
	room1 room2 room3 room4 room5 - room	
    door1 door2 door3 door4 door5 - door
)
(:init
	(in_room turtle room1)
	(connects door1 room1)
	(connects door1 room2)
	(connects door2 room2)
	(connects door4 room3)
	(connects door4 room4)
	(connects door5 room2)
	(connects door5 room4)
	(connects door3 room4)
	(connects door3 room5)


	




)
(:goal (and
	(in_room turtle room5)
	
)))