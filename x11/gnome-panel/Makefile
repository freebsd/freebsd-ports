# New ports collection makefile for:	gnomepanel
# Date created:				27 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome-panel/Makefile,v 1.230 2010/11/17 13:01:32 kwm Exp $
#

PORTNAME=	gnome-panel
PORTVERSION=	2.32.1
PORTREVISION?=	0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Panel component for the GNOME 2 Desktop

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	gweather.1:${PORTSDIR}/net/libgweather \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		canberra-gtk.0:${PORTSDIR}/audio/libcanberra

USE_GETTEXT=	yes
USE_XORG=	ice sm x11 xau xrandr
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedesktop libwnck gnomemenus \
		gnomedocutils ltverhack referencehack librsvg2
WANT_GNOME=	yes
GNOME_DESKTOP_VERSION=2
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-network-manager \
		--enable-polkit
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gnome-panel.1
GCONF_SCHEMAS=	clock.schemas fish.schemas \
		panel-compatibility.schemas panel-general.schemas \
		panel-global.schemas panel-object.schemas \
		panel-toplevel.schemas window-list.schemas \
		workspace-switcher.schemas

OPTIONS=	EVOLUTION "use the Evolution calendar if installed" on \
		BONOBO "Support for bonobo applets aka Gnome 2 applets" on

.if defined(PACKAGE_BUILDING)
.undef WITHOUT_GNOME
WITH_GNOME=	yes
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_EVOLUTION) && ${HAVE_GNOME:Mevolutiondataserver}!=""
USE_GNOME+=	evolutiondataserver
#CONFIGURE_ARGS+=--enable-eds
.else
CONFIGURE_ARGS+=--disable-eds
.endif

.if defined(WITH_BONOBO)
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

post-install:
	@${MKDIR} ${PREFIX}/lib/gnome-panel/modules
	-${LOCALBASE}/bin/gio-querymodules ${PREFIX}/lib/gnome-panel/modules

.include <bsd.port.post.mk>

.endif
