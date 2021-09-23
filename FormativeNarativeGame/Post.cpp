#include "Post.h"


const char* get_post_text(const Post planet)
{
	switch (planet) {
	case Post::Captain:
		return "Captain";
	case Post::Pilot:
		return "Pilot";
	case Post::Child:
		return "Child";
	}

	return "NO NAME";
}
