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

LIB_DEPENDS=	guile.10:${PORTSDIR}/lang/guile
RUN_DEPENDS=	${X11BASE}/share/scwm/pixmaps/Animator.xpm:${PORTSDIR}/graphics/scwm-icons

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	esound imlib
USE_GMAKE=	yes
USE_XPM=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS+=	--with-guile-prefix=${LOCALBASE}
CONFIGURE_ENV+=	CPPFLAGS="-I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.if defined(WITH_I18N)
CONFIGURE_ARGS+=	--enable-multibyte=yes
CONFIGURE_ENV+=	LIBS="-L${X11BASE}/lib -lxpg4"
.endif

MAN1=		scwm.1 scwmexec.1 scwmrepl.1

pre-patch:
	@${PERL} -pi -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/utilities/libscwmexec/libmain.c

post-install:
	${RM} -rf ${PREFIX}/share/scwm/ViaVoice

.include <bsd.port.mk>
