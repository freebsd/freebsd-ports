# New ports collection makefile for:   scwm
# Version required:    0.9
# Date created:        26 December 1997
# Whom:                Yukihiro Nakai <nacai@iname.com>
#
# $FreeBSD$
#

DISTNAME=	scwm-0.9
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://huis-clos.mit.edu/pub/scwm/

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	guile.4:${PORTSDIR}/lang/guile \
		Xpm.4:${PORTSDIR}/graphics/xpm
RUN_DEPENDS=	${X11BASE}/include/X11/pixmaps/Animator.xpm:${PORTSDIR}/graphics/scwm-icons

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-guile-prefix=${LOCALBASE}
.if defined(MULTIBYTE)
CONFIGURE_ARGS+=	--enable-multibyte=yes
CONFIGURE_ENV+= LIBS="-lxpg4"
.endif
USE_GMAKE=	yes
USE_X_PREFIX=	yes

MAN1=		scwm.1 scwmexec.1 scwmrepl.1

post-install:
	${INSTALL_DATA} ${WRKSRC}/sample.scwmrc/*.scwmrc \
			${PREFIX}/lib/X11/scwm

.include <bsd.port.mk>
