extends Node3D

@export var character : MMCharacter
@export var nav_agent : NavigationAgent3D
@export var speed = 3.0

func _unhandled_input(event: InputEvent) -> void:
	if event.is_action_pressed("ui_accept"):
		var random_pos: = Vector3.ZERO
		random_pos.x = randf_range(-5.0, 5.0)
		random_pos.z = randf_range(-5.0, 5.0)
		nav_agent.target_position = random_pos
		print(random_pos)

func _physics_process(delta: float) -> void:
	var next_destination = nav_agent.get_next_path_position()
	var delta_pos_next = next_destination - global_position
	 
	var distance_remaining = nav_agent.get_final_position().distance_to(global_position)
	character.target_velocity = delta_pos_next
	if distance_remaining > speed:
		character.target_velocity = delta_pos_next.normalized() * speed
	nav_agent.velocity = character.velocity
