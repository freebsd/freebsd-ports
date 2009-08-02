# New ports collection makefile for:	openbox
# Date created:				2002-04-28
# Whom:					trevor
# based on the blackbox port
#
# $FreeBSD$
#

PORTNAME=	openbox
PORTVERSION=	3.4.7.2
CATEGORIES=	x11-wm
MASTER_SITES=	http://offload1.icculus.org/openbox/releases/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	A standards compliant, fast, light-weight, extensible window manager

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/libXft

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 libxml2 ltverhack
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAN1=		openbox.1 openbox-session.1 \
		openbox-gnome-session.1 openbox-kde-session.1

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(WITHOUT_PANGO)
USE_GNOME+=	pango
.else
CONFIGURE_ARGS+=	--disable-pango
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

post-configure:
	@${CHMOD} +x ${WRKSRC}/install-sh

.include <bsd.port.mk>
