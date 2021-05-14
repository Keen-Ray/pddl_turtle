echo "Placing in Doors"
rosrun pddl_turtle doors.py

echo "Generating a Problem and Plan"
time rosservice call /rosplan_problem_interface/problem_generation_server 
time rosservice call /rosplan_planner_interface/planning_server

echo "Executing the Plan"
time rosservice call /rosplan_parsing_interface/parse_plan
time rosservice call /rosplan_plan_dispatcher/dispatch_plan