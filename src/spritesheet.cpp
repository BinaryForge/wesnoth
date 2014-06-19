#include "spritesheet.hpp"

#include "config.hpp"
#include "log.hpp"
#include "util.hpp"
#include "wml_exception.hpp"

static lg::log_domain log_config("config");
#define WRN_CF LOG_STREAM(warn, log_config)

// Spritesheet data structure for each sprite's location

sprite_data::sprite_data(const config& cfg) :
	image(cfg["spritesheet"]),
	id(cfg["id"].to_int()),
	x_coor(cfg["x_coor"].to_int()),
	y_coor(cfg["y_coor"].to_int()),
	height(cfg["height"].to_int()),
	width(cfg["width"].to_int())
{
	VALIDATE(!image.empty(), missing_mandatory_wml_key("spritesheet", "spritesheet_image"));
}

