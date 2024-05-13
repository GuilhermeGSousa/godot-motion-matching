@tool
extends EditorPlugin

var mm_lib_editor : MMAnimationLibraryEditor = preload("res://addons/motion_matching/MMAnimationLibraryEditor.tscn").instantiate()

var last_path := ""

func _enter_tree() -> void:
	# Initialization of the plugin goes here.
	pass


func _exit_tree() -> void:
	remove_control_from_bottom_panel(mm_lib_editor)
	mm_lib_editor.queue_free()

func _input(event: InputEvent) -> void:
	if event is InputEventMouseButton and event.is_released():
		if last_path != get_editor_interface().get_current_path():
			last_path = get_editor_interface().get_current_path()
			remove_control_from_bottom_panel(mm_lib_editor)
			visibility()


func visibility():
	var current_path = get_editor_interface().get_current_path()
	
	if not ResourceLoader.exists(current_path):
		return
		
	var l = ResourceLoader.load(current_path)
	
	if l is MMAnimationLibrary:
		prints("Selected MMAL",l.resource_path)

		add_control_to_bottom_panel(mm_lib_editor,"MotionMatching")
		make_bottom_panel_item_visible(mm_lib_editor)
		mm_lib_editor.library = l
		mm_lib_editor.update_info()
	else :
		remove_control_from_bottom_panel(mm_lib_editor)
