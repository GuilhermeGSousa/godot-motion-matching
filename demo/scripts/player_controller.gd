extends Node

@export var max_speed = 3.0
@export var jump_speed = 3.0
@export var character: MMCharacter
@export var camera_pivot: Node3D

func _physics_process(delta: float) -> void:
	var stick_input = Input.get_vector("left", "right", "down", "up")
	var stick_input_world = Vector3(-stick_input.x, 0, stick_input.y)
	var desired_velocity = (stick_input_world * max_speed).rotated(Vector3.UP, camera_pivot.rotation.y)
	character.target_velocity = desired_velocity

func _input(event: InputEvent) -> void:
	if event.is_action_pressed("jump") and character.is_on_floor():
		character.velocity += Vector3.UP * jump_speed
