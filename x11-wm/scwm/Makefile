# New ports collection makefile for:   scwm
# Version required:    0.8a
# Date created:        26 December 1997
# Whom:                Yukihiro Nakai <Nakai@technologist.com
#
# $Id$
#

DISTNAME=	scwm-0.8a
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://huis-clos.mit.edu/pub/scwm/

MAINTAINER=	Nakai@technologist.com

LIB_DEPENDS=	guile.4:${PORTSDIR}/lang/guile \
		Xpm.4:${PORTSDIR}/graphics/xpm
RUN_DEPENDS=	${X11BASE}/include/X11/pixmaps/Animator.xpm:${PORTSDIR}/graphics/scwm-icons

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-guile-prefix=${LOCALBASE}
#CONFIGURE_ARGS+=	--enable-multibyte=yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

MAN1=		scwm.1 scwmexec.1 scwmrepl.1

pre-patch:
.if defined(I18N)
	${CP} ${FILESDIR}/patch-ab ${PATCHDIR}
	${CP} ${FILESDIR}/patch-ac ${PATCHDIR}
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/sample.scwmrc/*.scwmrc \
			${PREFIX}/lib/X11/scwm

.include <bsd.port.mk>
