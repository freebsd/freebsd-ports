# New ports collection makefile for:   icewm
# Version required:    0.9.16
# Date created:        10 August 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.19 1998/11/11 13:24:53 vanilla Exp $
#

DISTNAME=	icewm-0.9.16
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.kiss.uni-lj.si/~k4fr0235/icewm/devel/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	Nakai@technologist.com

.if defined(GNOME)
BUILD_DEPENDS+=	gnome-config:${PORTSDIR}/x11/gnomelibs
BUILD_DEPENDS+=	imlib-config:${PORTSDIR}/graphics/imlib
BUILD_DEPENDS+=	${LOCALBASE}/lib/libintl.a:${PORTSDIR}/devel/gettext
.endif
LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_GMAKE=	yes
USE_X_PREFIX=	yes

ICEOPTION=	--with-shape
.if defined(I18N)
ICEOPTION+=	--with-i18n
.endif
.if defined(GNOME)
ICEOPTION+=	--with-imlib --with-gnome
.endif

pre-patch:
.if defined(TITLE_BOTTOM)
	${CP} ${FILESDIR}/patch-titlebottom ${PATCHDIR}/patch-ac
.else
	${CP} ${FILESDIR}/patch-titletop ${PATCHDIR}/patch-ac
.endif
.if defined(GNOME)
	${CP} ${FILESDIR}/patch-gnome ${PATCHDIR}
.endif

do-configure:
	( cd ${WRKSRC}; ${SH} config ${ICEOPTION} )

post-install:
	${CP} ${FILESDIR}/bsd-daemon.xpm ${PREFIX}/lib/X11/icewm/taskbar
	strip ${PREFIX}/bin/icewm
	strip ${PREFIX}/bin/icewmbg
	strip ${PREFIX}/bin/icewmhint

.include <bsd.port.mk>
