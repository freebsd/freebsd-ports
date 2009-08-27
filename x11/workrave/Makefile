# New ports collection makefile for:	workrave
# Date created:				15 Jul 2003
# Whom:					Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTNAME=	workrave
PORTVERSION=	1.8.5
PORTREVISION=	5
CATEGORIES=	x11 gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Gnome RSI prevention tool

OPTIONS=	GNOME "Build with Gnome support" on \
		NETWORK "Build with network support" on

USE_XORG=	x11 xmu
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gconf2 intltool
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include `pkg-config --cflags libgnomeui-2.0`" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="`pkg-config --libs libgnomeui-2.0`"
CONFIGURE_ARGS=	--enable-gconf

.include <bsd.port.pre.mk>

.if defined(WITH_GNOME)
LIB_DEPENDS+=	gnomeuimm-2.6.1:${PORTSDIR}/x11-toolkits/libgnomeuimm26
USE_GNOME+=	gnomepanel
PLIST_SUB+=	GNOME=""
.else
LIB_DEPENDS+=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24
CONFIGURE_ARGS+=--disable-gnome
PLIST_SUB+=	GNOME="@comment "
.endif

.if defined(WITH_NETWORK)
LIB_DEPENDS+=	gnet-2.0.0:${PORTSDIR}/net/gnet2
.else
CONFIGURE_ARGS+=--disable-distribution
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|#include <sigc++\/compatibility\.h>||g ; \
		s|SigC::Signal|sigc::signal|g ; \
		s|SigC::slot_class|sigc::mem_fun|g ; \
		s|SigC::Connection|sigc::connection|g ; \
		s|SigC::Slot|sigc::slot|g ; \
		s|SigC::Object|sigc::trackable|g ; \
		s|SigC::slot|sigc::mem_fun|g' \
			${WRKSRC}/frontend/gtkmm/src/*.* \
			${WRKSRC}/frontend/plugin/*/gtkmm/src/*.*

.include <bsd.port.post.mk>
