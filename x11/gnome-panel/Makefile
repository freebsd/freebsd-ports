# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11/gnome-panel/Makefile,v 1.237 2012/10/25 09:21:00 kwm Exp $

PORTNAME=	gnome-panel
PORTVERSION=	2.32.1
PORTREVISION?=	3
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Panel component for the GNOME 2 Desktop

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	gweather:${PORTSDIR}/net/libgweather \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		canberra-gtk:${PORTSDIR}/audio/libcanberra

CONFLICTS=	gnome-panel-3.[0-9]*

USE_XORG=	ice sm x11 xau xrandr
USE_PYTHON=	-2.7
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USES=		pathfix gettext gmake pkgconfig
USE_GNOME=	gnomeprefix intlhack gnomedesktop libwnck gnomemenus \
		gnomedocutils ltverhack referencehack librsvg2
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-network-manager
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

MAN1=		gnome-panel.1
GCONF_SCHEMAS=	clock.schemas fish.schemas \
		panel-compatibility.schemas panel-general.schemas \
		panel-global.schemas panel-object.schemas \
		panel-toplevel.schemas window-list.schemas \
		workspace-switcher.schemas

OPTIONS_DEFINE=	EVOLUTION BONOBO
OPTIONS_DEFAULT=EVOLUTION BONOBO
EVOLUTION_DESC=	Use the Evolution calendar
BONOBO_DESC=	Support for bonobo applets aka Gnome 2 applets

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEVOLUTION}
USE_GNOME+=	evolutiondataserver
#CONFIGURE_ARGS+=--enable-eds
.else
CONFIGURE_ARGS+=--disable-eds
.endif

.if ${PORT_OPTIONS:MBONOBO}
USE_GNOME+=	libbonoboui
CONFIGURE_ARGS+=--enable-bonobo
PLIST_SUB+=	BONOBO=""
.else
CONFIGURE_ARGS+=--disable-bonobo
PLIST_SUB+=	BONOBO="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|"applications.menu"|"gnome-applications.menu"|'
	@${REINPLACE_CMD} -e 's|xsltproc -o| xsltproc --nonet -o|g' \
		${WRKSRC}/help/clock/Makefile.in \
		${WRKSRC}/help/fish/Makefile.in
	@${REINPLACE_CMD} -e 's|python.* python2\.0|${PYTHON_VERSION}|g' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${PREFIX}/lib/gnome-panel/modules
	-${LOCALBASE}/bin/gio-querymodules ${PREFIX}/lib/gnome-panel/modules

.include <bsd.port.mk>

.endif
