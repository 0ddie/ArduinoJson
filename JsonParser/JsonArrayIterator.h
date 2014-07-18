/*
* Arduino JSON library
* Benoit Blanchon 2014 - MIT License
*/

#pragma once

#include "JsonValue.h"
#include "JsonToken.h"

namespace ArduinoJson
{
    namespace Parser
    {
        class JsonArrayIterator
        {
        public:

            JsonArrayIterator(char* json, Internal::JsonToken token)
                : json(json), token(token)
            {

            }

            void operator++()
            {
                token = token.nextSibling();
            }

            JsonValue operator*() const
            {
                return JsonValue(json, token);
            }

            bool operator !=(const JsonArrayIterator& other)
            {
                return token != other.token;
            }

        private:

            char* json;
            Internal::JsonToken token;
        };
    }
}