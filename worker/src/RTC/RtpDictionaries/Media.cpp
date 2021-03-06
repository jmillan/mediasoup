#define MS_CLASS "RTC::Media"

#include "RTC/RtpDictionaries.h"
#include "Utils.h"
#include "MediaSoupError.h"
#include "Logger.h"

namespace RTC
{
	/* Class variables. */

	std::unordered_map<std::string, Media::Kind> Media::string2Kind =
	{
		{ "",      Media::Kind::ALL   },
		{ "audio", Media::Kind::AUDIO },
		{ "video", Media::Kind::VIDEO },
		{ "depth", Media::Kind::DEPTH }
	};

	std::map<Media::Kind, Json::StaticString> Media::kind2Json =
	{
		{ Media::Kind::ALL,   Json::StaticString("")      },
		{ Media::Kind::AUDIO, Json::StaticString("audio") },
		{ Media::Kind::VIDEO, Json::StaticString("video") },
		{ Media::Kind::DEPTH, Json::StaticString("depth") }
	};

	/* Class methods. */

	Media::Kind Media::GetKind(std::string& str)
	{
		MS_TRACE();

		// Force lowcase kind.
		Utils::String::ToLowerCase(str);

		auto it = Media::string2Kind.find(str);

		if (it == Media::string2Kind.end())
			MS_THROW_ERROR("invalid media kind [kind:%s]", str.c_str());

		return it->second;
	}

	Json::StaticString& Media::GetJsonString(Media::Kind kind)
	{
		MS_TRACE();

		return Media::kind2Json.at(kind);
	}
}
