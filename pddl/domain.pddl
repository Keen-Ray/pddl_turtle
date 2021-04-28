(define (domain pddl_turtle)

(:requirements :strips :typing :disjunctive-preconditions)

(:types
	robot
	room
	door
)

(:predicates

	;;robot predicates

	(in_room ?v - robot ?r - room)

	;;door/room predicates

	(at_door ?v - robot ?d - door)
	(open ?d - door)
	(connects  ?d - door ?r - room)
)


;; Move to any waypoint, avoiding terrain
(:action go_through
	:parameters (?v - robot ?d - door ?from ?to - room)
	:precondition (and
		(at_door ?v ?d)
		(open ?d)
		(connects ?d ?from)
		(connects ?d ?to)
		(in_room ?v ?from)
		)
	:effect (and
		(in_room ?v ?to)
		(not (in_room ?v ?from))
		)
)


(:action go_to_door
	:parameters (?v - robot ?from - room ?d - door)
	:precondition (and
		(in_room ?v ?from)
		(connects ?d ?from)
		
		)
	:effect (and
		(at_door ?v ?d)
		)
)

(:action open_door
	:parameters (?v - robot ?d - door)
	:precondition (and
		(at_door ?v ?d)
	
		)
	:effect (and
		(open ?d)
		)
)




)