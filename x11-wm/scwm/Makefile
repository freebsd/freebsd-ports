# New ports collection makefile for:   scwm
# Date created:        26 December 1997
# Whom:                Yukihiro Nakai <nacai@iname.com>
#
# $FreeBSD$
#

PORTNAME=	scwm
PORTVERSION=	0.99.6.1
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://scwm.mit.edu/pub/scwm/

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	guile.6:${PORTSDIR}/lang/guile \
		Imlib.5:${PORTSDIR}/graphics/imlib \
		esd.2:${PORTSDIR}/audio/esound \
		Xpm.4:${PORTSDIR}/graphics/xpm
RUN_DEPENDS=	${X11BASE}/share/scwm/pixmaps/Animator.xpm:${PORTSDIR}/graphics/scwm-icons

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS+=	--with-guile-prefix=${LOCALBASE}
CONFIGURE_ENV+=	CPPFLAGS="-I${X11BASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.if defined(MULTIBYTE)
CONFIGURE_ARGS+=	--enable-multibyte=yes
CONFIGURE_ENV+=	LIBS="-L${X11BASE}/lib -lxpg4"
.endif
USE_GMAKE=	yes
USE_X_PREFIX=	yes

MAN1=		scwm.1 scwmexec.1 scwmrepl.1

post-install:
		${RM} -rf ${PREFIX}/share/scwm/ViaVoice

.include <bsd.port.mk>
