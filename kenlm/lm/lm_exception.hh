#ifndef LM_LM_EXCEPTION__
#define LM_LM_EXCEPTION__

// Named to avoid conflict with util/exception.hh.  

#include "util/exception.hh"
#include "util/string_piece.hh"

#include <exception>
#include <string>

namespace lm {

class LoadException : public util::Exception {
   public:
      virtual ~LoadException() throw();

   protected:
      LoadException() throw();
};

class VocabLoadException : public LoadException {
  public:
    virtual ~VocabLoadException() throw();
    VocabLoadException() throw();
};

class FormatLoadException : public LoadException {
  public:
    FormatLoadException() throw();
    ~FormatLoadException() throw();
};

class SpecialWordMissingException : public VocabLoadException {
  public:
    explicit SpecialWordMissingException(StringPiece which) throw();
    ~SpecialWordMissingException() throw();
};

} // namespace lm

#endif // LM_LM_EXCEPTION
