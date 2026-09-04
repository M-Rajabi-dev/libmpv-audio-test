#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ass/ass.h>

int ass_library_version(void) { return LIBASS_VERSION; }

ASS_Library *ass_library_init(void) {
    return (ASS_Library *)calloc(1, sizeof(void *));
}

void ass_library_done(ASS_Library *priv) {
    free(priv);
}

void ass_set_fonts_dir(ASS_Library *priv, const char *fonts_dir) {}
void ass_set_extract_fonts(ASS_Library *priv, int extract) {}
void ass_set_style_overrides(ASS_Library *priv, char **list) {}
void ass_process_force_style(ASS_Track *track) {}
void ass_set_message_cb(ASS_Library *priv, void (*msg_cb)(int, const char *, va_list, void *), void *data) {}

ASS_Renderer *ass_renderer_init(ASS_Library *priv) {
    return (ASS_Renderer *)calloc(1, sizeof(void *));
}

void ass_renderer_done(ASS_Renderer *priv) {
    free(priv);
}

void ass_set_frame_size(ASS_Renderer *priv, int w, int h) {}
void ass_set_storage_size(ASS_Renderer *priv, int w, int h) {}
void ass_set_shaper(ASS_Renderer *priv, ASS_ShapingLevel level) {}
void ass_set_margins(ASS_Renderer *priv, int t, int b, int l, int r) {}
void ass_set_use_margins(ASS_Renderer *priv, int use) {}
void ass_set_pixel_aspect(ASS_Renderer *priv, double par) {}
void ass_set_aspect_ratio(ASS_Renderer *priv, double dar, double sar) {}
void ass_set_font_scale(ASS_Renderer *priv, double font_scale) {}
void ass_set_hinting(ASS_Renderer *priv, ASS_Hinting ht) {}
void ass_set_line_spacing(ASS_Renderer *priv, double line_spacing) {}
void ass_set_line_position(ASS_Renderer *priv, double line_position) {}
void ass_get_available_font_providers(ASS_Library *priv, ASS_DefaultFontProvider **providers, size_t *size) {
    if (size) *size = 0;
}
void ass_set_fonts(ASS_Renderer *priv, const char *default_font, const char *default_family, int dfp, const char *config, int update) {}
void ass_set_selective_style_override_enabled(ASS_Renderer *priv, int bits) {}
void ass_set_selective_style_override(ASS_Renderer *priv, ASS_Style *style) {}
int ass_fonts_update(ASS_Renderer *priv) { return 0; }
void ass_set_cache_limits(ASS_Renderer *priv, int glyph_max, int bitmap_max_size) {}

ASS_Image *ass_render_frame(ASS_Renderer *priv, ASS_Track *track, long long now, int *detect_change) {
    if (detect_change) *detect_change = 0;
    return NULL;
}

int ass_alloc_style(ASS_Track *track) {
    if (!track) return -1;
    int sid = track->n_styles++;
    track->styles = (ASS_Style *)realloc(track->styles, sizeof(ASS_Style) * track->n_styles);
    if (!track->styles) return -1;
    memset(&track->styles[sid], 0, sizeof(ASS_Style));
    track->styles[sid].Name = strdup("Default");
    track->styles[sid].FontName = strdup("sans-serif");
    track->styles[sid].ScaleX = 100.0;
    track->styles[sid].ScaleY = 100.0;
    return sid;
}

int ass_alloc_event(ASS_Track *track) {
    if (!track) return -1;
    int eid = track->n_events++;
    track->events = (ASS_Event *)realloc(track->events, sizeof(ASS_Event) * track->n_events);
    if (!track->events) return -1;
    memset(&track->events[eid], 0, sizeof(ASS_Event));
    return eid;
}

ASS_Track *ass_new_track(ASS_Library *priv) {
    ASS_Track *track = (ASS_Track *)calloc(1, sizeof(ASS_Track));
    if (track) {
        track->default_style = ass_alloc_style(track);
    }
    return track;
}

int ass_track_set_feature(ASS_Track *track, ASS_Feature feature, int enable) { return 0; }

void ass_free_style(ASS_Track *track, int sid) {}
void ass_free_event(ASS_Track *track, int eid) {}

void ass_flush_events(ASS_Track *track) {
    if (!track) return;
    for (int i = 0; i < track->n_events; i++) {
        free(track->events[i].Text);
        free(track->events[i].Effect);
    }
    free(track->events);
    track->events = NULL;
    track->n_events = 0;
}

void ass_free_track(ASS_Track *track) {
    if (!track) return;
    for (int i = 0; i < track->n_styles; i++) {
        free(track->styles[i].Name);
        free(track->styles[i].FontName);
    }
    free(track->styles);
    ass_flush_events(track);
    free(track);
}

void ass_process_data(ASS_Track *track, const char *data, int size) {}
void ass_process_codec_private(ASS_Track *track, const char *data, int size) {}
void ass_process_chunk(ASS_Track *track, const char *data, int size, long long timecode, long long duration) {}
void ass_set_check_readorder(ASS_Track *track, int check_readorder) {}
void ass_prune_events(ASS_Track *track, long long deadline) {}
void ass_configure_prune(ASS_Track *track, long long delay) {}
ASS_Track *ass_read_file(ASS_Library *library, const char *fname, const char *codepage) { return NULL; }
ASS_Track *ass_read_memory(ASS_Library *library, char *buf, size_t bufsize, const char *codepage) { return NULL; }
int ass_read_styles(ASS_Track *track, const char *fname, const char *codepage) { return 0; }
void ass_add_font(ASS_Library *library, const char *name, const char *data, int data_size) {}
void ass_clear_fonts(ASS_Library *library) {}
long long ass_step_sub(ASS_Track *track, long long now, int movement) { return 0; }
void *ass_malloc(size_t size) { return malloc(size); }
void ass_free(void *ptr) { free(ptr); }
