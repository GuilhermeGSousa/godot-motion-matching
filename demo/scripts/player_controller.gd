extends Node

@export var max_speed = 3.0
@export var character : MMCharacter

func _physics_process(delta: float) -> void:
	var stick_input = Input.get_vector("left", "right", "down", "up")
	var stick_input_world = Vector3(-stick_input.x, 0, stick_input.y)
	
	character.target_velocity = stick_input_world * max_speed
