# New ports collection makefile for:	lxpanel
# Date created:		Sat Oct 7 01:22:35 CST 2006
# Whom:			Lin, Cheng-Tao <b89605222@ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	lxpanel
PORTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lxde

MAINTAINER=	b89605222@ntu.edu.tw
COMMENT=	LXPanel is a lightweight X11 desktop panel

USE_GNOME=	gtk20 gnomelibs gnomedesktop
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake:19
CONFIGURE_ARGS=	--prefix=${PREFIX}
CONFIGURE_ENV=	LDFLAGS="-L${X11BASE}/lib" CFLAGS="-I${LOCALBASE}/include"
CFLAGS+=	-I${WRKSRC}
USE_GMAKE=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's,linux,sys,' \
		${WRKSRC}/src/plugins/volume/volume-impl.c
	@${REINPLACE_CMD} -e 's,$$(DATADIRNAME)/locale,share/locale,' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
