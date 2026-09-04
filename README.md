# libmpv-audio-test

Test build of `libmpv-2.dll` for Windows with stubbed subtitle and OSD components.

## Overview
This repository tests building an ultra-compact version of `libmpv` by replacing the subtitle rendering engine (`libass`, `harfbuzz`, `freetype`, `fribidi`) with a lightweight stub.

## Details
- Video output, video decoders, and graphics APIs disabled
- Text rendering stack stubbed out to reduce binary footprint
- TLS support via Windows SChannel
- Standard audio formats and playback filters preserved

Prebuilt test binaries are available in [Releases](https://github.com/M-Rajabi-dev/libmpv-audio-test/releases).

## License
MIT
