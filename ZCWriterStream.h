ifndef __ZC_WRITER_STREAM_H__
#define __ZC_WRITER_STREAM_H__

#include <google/protobuf/io/zero_copy_stream.h>

namespace protobuf = google::protobuf;

class ZCWriterStream : public protobuf::io::ZeroCopyOutputStream {
public:
  ZCWriterStream(
    int fd,
    protobuf::uint8* pDataBuffer,
    protobuf::uint32 bufferSize);

  virtual ~ZCWriterStream();

  virtual bool Next(void** data, int* size);

  virtual void BackUp(int count);

  virtual protobuf::int64 ByteCount() const;

  bool Flush();

private:
  int m_fd;
  protobuf::uint8* m_pDataBuffer;
  const protobuf::uint32 m_bufferSize;
  protobuf::uint32 m_numBytesToWrite;
  protobuf::uint32 m_byteCount;

private:
 GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(ZCWriterStream);
};

#endif // __ZERO_COPY_NETWORK_WRITER_STREAM_H__
