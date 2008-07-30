# New ports collection makefile for:	beryl-core
# Date created:				Oct 29 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	beryl-core
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.beryl-project.org/${PORTVERSION}/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	flz/beryl/

MAINTAINER=	rnoland@FreeBSD.org
COMMENT=	Beryl Composite/Window Manager

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser

GNU_CONFIGURE=	yes
USE_GL=		gl
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20 gconf2
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_PERL5=	yes

DEPRECATED=	No longer supported - Use compiz
EXPIRATION_DATE=	2008-08-02

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--disable-berylmesa
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib  ${PTHREAD_LIBS}"

USE_XORG=	xcomposite xfixes xdamage xrandr ice sm xinerama glproto

MAN1=		beryl.1			\
		beryl-xgl.1		\
		beryl-settings-dump.1

MAN3=		beryl_settings_context_new.3				\
		beryl_settings_context_destroy.3			\
		beryl_settings_context_find_plugin.3			\
		beryl_settings_context_find_setting.3			\
		beryl_settings_context_read.3				\
		beryl_settings_context_write.3				\
		beryl_settings_context_comp_new.3			\
		beryl_settings_context_comp_add_plugin.3		\
		beryl_settings_context_comp_add_option.3		\
		beryl_settings_context_comp_get_option_value.3		\
		beryl_settings_context_comp_set_option_value.3		\
		beryl_settings_send_reload_signal.3			\
		beryl_setting_reset_to_default.3			\
		beryl_setting_list_clear.3				\
		beryl_setting_list_append.3				\
		beryl_setting_list_length.3				\
		beryl_setting_list_value_index.3			\
		beryl_setting_list_value_swap_with.3			\
		beryl_setting_list_value_move_before.3			\
		beryl_setting_list_value_remove.3			\
		beryl_setting_get_primary_value.3			\
		beryl_setting_value_get_int.3				\
		beryl_setting_value_get_float.3				\
		beryl_setting_value_get_bool.3				\
		beryl_setting_value_get_string.3			\
		beryl_setting_value_get_keysym.3			\
		beryl_setting_value_get_keymods.3			\
		beryl_setting_value_get_button.3			\
		beryl_setting_value_get_buttonmods.3			\
		beryl_setting_value_get_bell.3				\
		beryl_setting_value_get_edgemask.3			\
		beryl_setting_value_get_key_enabled.3			\
		beryl_setting_get_int_min.3				\
		beryl_setting_value_get_button_enabled.3		\
		beryl_setting_value_get_color.3				\
		beryl_setting_value_get_value_list.3			\
		beryl_setting_value_set_int.3				\
		beryl_setting_value_set_float.3				\
		beryl_setting_value_set_bool.3				\
		beryl_setting_value_set_string.3			\
		beryl_setting_value_set_keysym.3			\
		beryl_setting_value_set_keymods.3			\
		beryl_setting_value_set_button.3			\
		beryl_setting_value_set_buttonmods.3			\
		beryl_setting_value_set_bell.3				\
		beryl_setting_value_set_edgemask.3			\
		beryl_setting_value_set_key_enabled.3			\
		beryl_setting_value_set_button_enabled.3		\
		beryl_setting_value_set_color.3				\
		beryl_setting_get_can_set_key.3				\
		beryl_setting_get_can_set_button.3			\
		beryl_setting_get_can_set_edgemask.3			\
		beryl_setting_get_can_set_bell.3			\
		beryl_setting_get_allowed_strings.3			\
		beryl_setting_get_int_max.3				\
		beryl_setting_get_float_min.3				\
		beryl_setting_get_float_max.3				\
		beryl_setting_get_float_precision.3			\
		beryl_setting_get_list_type.3				\
		beryl_setting_get_type.3				\
		beryl_setting_get_short_desc.3				\
		beryl_setting_get_long_desc.3				\
		beryl_setting_get_name.3				\
		beryl_settings_plugin_get_short_desc.3			\
		beryl_settings_plugin_get_long_desc.3			\
		beryl_settings_plugin_get_name.3			\
		beryl_settings_context_get_plugins.3			\
		beryl_settings_plugin_get_settings.3			\
		beryl_settings_context_get_private.3			\
		beryl_settings_plugin_get_private.3			\
		beryl_setting_get_private.3				\
		beryl_settings_context_set_private.3			\
		beryl_settings_plugin_set_private.3			\
		beryl_setting_set_private.3				\
		beryl_settings_set_codeset.3

post-patch:
	@${REINPLACE_CMD} -e 's|libpng|libpng12|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|.[(]top_srcdir[)]/mesa/lib/libGL.a |-lGL |'	\
		-e 's|.[(]top_srcdir[)]/mesa/lib/libGL.a|-lGL|'			\
			${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|\(Libs.*\)|\1 -lGL|' ${WRKSRC}/beryl.pc.in
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|'				\
			${WRKSRC}/libberylsettings/main.c			\
			${WRKSRC}/src/plugin.c					\
			${WRKSRC}/src/display_options.c				\
			${WRKSRC}/settings-backends/ini.c			\
			${WRKSRC}/settings-backends/gconf.c

.include <bsd.port.mk>
