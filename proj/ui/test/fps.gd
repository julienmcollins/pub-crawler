extends RichTextLabel

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	var fps = Engine.get_frames_per_second()
	text = ""
	text += "FPS: " + str(fps)
	
	if fps < 50:
		add_theme_color_override("default_color", Color.RED)
	else:
		add_theme_color_override("default_color", Color.GREEN)
