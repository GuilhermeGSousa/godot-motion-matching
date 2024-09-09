extends Node3D

@export var charater : MMCharacter
@export var sensitivity = 0.5

var height = 0

func _ready() -> void:
	height = global_position.y
	Input.mouse_mode = Input.MOUSE_MODE_CAPTURED
	
	
func _input(event: InputEvent) -> void:
	if event is InputEventMouseMotion:
		var mouse_event : InputEventMouseMotion = event
		var rot = mouse_event.relative * sensitivity * -1
		var current_rot = rotation_degrees
		current_rot.x += rot.y
		current_rot.x = clampf(current_rot.x, -30, 30)
		current_rot.y += rot.x
		rotation_degrees = current_rot

func _process(delta: float) -> void:
	global_position = charater.global_position
	global_position.y += height
	charater.strafe_facing = rotation.y
