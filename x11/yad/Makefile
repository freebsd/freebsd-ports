# $FreeBSD$

PORTNAME=	yad
PORTVERSION=	0.22.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	Display GNOME dialogs from the command line

USE_GMAKE=	yes
USE_XZ=		yes
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV+=	DATADIRNAME=share

MAKE_JOBS_SAFE=	yes

MAN1=	yad.1

OPTIONS_DEFINE=	NLS

OPTIONS_SINGLE=	GTK
OPTIONS_SINGLE_GTK=	GTK2 GTK3

OPTIONS_DEFAULT=	GTK2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
USES+=		gettext
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=	--disable-nls
.endif

.if ${PORT_OPTIONS:MGTK3}
USE_GNOME=	gtk30
CONFIGURE_ARGS+=	--with-gtk=gtk3
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME=	gtk20
CONFIGURE_ARGS+=	--with-gtk=gtk2
.endif

post-configure:
.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} -e '/^SUBDIRS =/ s/ po//' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
