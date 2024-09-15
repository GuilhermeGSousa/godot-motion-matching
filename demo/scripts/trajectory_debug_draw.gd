extends Node

@export var character : Node3D
@export var controller : MMCharacter
@export var anim_player : AnimationPlayer

func _ready():
	controller.on_query_result.connect(_on_query_result)

func _physics_process(delta: float) -> void:
	DebugDraw3D.draw_position(character.transform, Color.FOREST_GREEN)
	DebugDraw3D.draw_position(controller.transform, Color.TOMATO)
	
	_draw_trajectory(controller.get_trajectory(), Color.AQUAMARINE, true)
	_draw_trajectory(controller.get_previous_trajectory(), Color.AQUA, true)

	var forward = controller.global_basis.z
	DebugDraw3D.draw_arrow(controller.global_position, controller.global_position + forward * 0.5, Color.DARK_SLATE_BLUE, .1)
		
func _draw_trajectory(trajectory : Array[Dictionary], color : Color, include_facing : bool, duration = 0):
	var trajectory_points = []
	for p in trajectory:
		var pos = p["position"]
		trajectory_points.push_back(pos)
		
		if include_facing:
			var dir = Vector3.FORWARD.rotated(Vector3.UP, p["facing"])
			DebugDraw3D.draw_arrow(pos, pos - dir * 0.25, Color.ORANGE, 0.01, false, duration)
	DebugDraw3D.draw_points(trajectory_points, DebugDraw3D.POINT_TYPE_SPHERE, 0.01, color, duration)

func _input(event: InputEvent) -> void:
	if event.is_action_pressed("switch_anim"):
		controller.is_strafing = !controller.is_strafing

func _on_query_result(data : Dictionary):
	var result_data = data["frame_data"]
	
	if result_data.is_empty():
		return
	
	var library : MMAnimationLibrary = anim_player.get_animation_library(anim_player.get_animation_library_list()[0])
	
	var offset = 0
	for feature in library.features:
		var start_index = offset
		var end_index = start_index + feature.get_dimension_count()
		
		var feature_data = result_data.slice(start_index, end_index)
		
		if feature is MMTrajectoryFeature:
			_draw_trajectory(feature.get_trajectory_points(character.transform, feature_data), Color.CRIMSON, false, 0.5) # feature.include_facing)

		offset += feature.get_dimension_count()
	
