(define (domain pddl_turtle)

(:requirements :strips :typing :disjunctive-preconditions :durative-actions)

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

(:durative-action open_door
	:parameters (?v - robot ?d - door)
	:duration ( = ?duration 2)
	:condition (and
		(at start (at_door ?v ?d))

		)
	:effect (and
		(at end (open ?d))
		)
)

;; Move to any waypoint, avoiding terrain
(:durative-action go_through
	:parameters (?v - robot ?d - door ?from ?to - room)
	:duration ( = ?duration 10)
	:condition (and
		(at start (at_door ?v ?d))
		(at start (open ?d))
		(at start (connects ?d ?from))
		(at start (connects ?d ?to))
		(at start (in_room ?v ?from))
		)
	:effect (and
		(at end (in_room ?v ?to))
		(at start (not (in_room ?v ?from)))
		)
)


(:durative-action go_to_door
	:parameters (?v - robot ?from - room ?d - door)
	:duration ( = ?duration 20)
	:condition (and
		(at start (in_room ?v ?from))
		(at start (connects ?d ?from))
		
		)
	:effect (and
		(at end (at_door ?v ?d))
		)
)

)